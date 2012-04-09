CXX = clang++
CXXFLAGS = -g -W -Wall
LDFLAGS = -g
SOURCES = net.cpp gate.cpp
OBJECTS = $(SOURCES:.cpp=.o)
DEPLOY_FOLDER = pa5
BINARY = gatesim

gatesim: $(OBJECTS) gatesim.cpp
	$(CXX) $(LDFLAGS) -o $@ $^

test_binary: $(OBJECTS) tests.cpp
	$(CXX) $(LDFLAGS) -o tests $^

tests: test_binary
	./tests

clean::
	$(RM) $(BINARY)
	$(RM) test_suite

.cpp.o:
	$(CXX) -MMD -MP $(CXXFLAGS) -o $@ -c $<

clean::
	$(RM) *.o
	$(RM) *.gch

DEPENDS = $(SOURCES:.cpp=.d)

-include $(DEPENDS)

%.d:
	@touch $@

clean::
	$(RM) *.d



# Generate documentation (requires pandoc, doxygen, pdftk)
.PHONY: doc
doc:
	doxygen Doxyfile
		
	cd design; \
	markdown2pdf design.md; \
	
	cd doc/latex; \
	make
	
	pdftk design/design.pdf doc/latex/refman.pdf cat output design_doc.pdf

clean::
	$(RM) -r doc
	$(RM) design/*.pdf
	$(RM) -r $(DEPLOY_FOLDER)
	$(RM) $(DEPLOY_FOLDER).tar.gz
	
.PHONY: deploy
deploy: build
	scp $(DEPLOY_FOLDER).zip licy@parallel05.usc.edu:~/

.PHONY: build
build: clean
	export COPYFILE_DISABLE=true
	mkdir -p $(DEPLOY_FOLDER)
	cp -R *.cpp *.h $(DEPLOY_FOLDER)/
	cp Makefile $(DEPLOY_FOLDER)/Makefile
	$(RM) $(DEPLOY_FOLDER)/.DS_Store
	zip -r $(DEPLOY_FOLDER) $(DEPLOY_FOLDER)
  
makefiles:
	make clean > DeployMakefile
	make >> DeployMakefile
