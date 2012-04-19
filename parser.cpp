#include "parser.h"

Design *parseThatShit(string ifilename)
{
	Design *theDesign = new Design;
	vector<string> port_list;
	vector<string>::iterator it;
	//vector<string> inputs;
	//vector<string> outputs;
	//vector<string> wires;
	vector<string> gate;
	
  unsigned int lineNum = 0;
	ifstream ifile(ifilename.c_str(), ifstream::in);
	while(ifile.good())
	{
    lineNum++;
		
		string currentline;
		getline(ifile, currentline);
		stringstream ss(currentline);
		string firsttoken;
		ss >> firsttoken;
		try{
			switch(lineType(firsttoken))
 			{
 				case COMMENT :
 					// comment line
 					LOG("Comment line found");
 					break;
 				case BLANK :
 					LOG("Blank line found");
 					break;
 				case MODULE :
 				{
 					// line defining a module
 					LOG("Module line");
 					string possibleIDModule;
 					getline(ss ,possibleIDModule, '(');
 					if(regex_match(possibleIDModule, ID))	{
 						// was an id
 						string designName = removeWhitespace(possibleIDModule);
 						theDesign->make_name(designName);
 						LOG("Module ID:");
 						LOG(designName);
 					}
 					
 					string possiblePortsModule;
 					getline(ss, possiblePortsModule, ')');
 					parenParser(&port_list, possiblePortsModule);
 					LOG("Module port list:");
 					for(it=port_list.begin();it < port_list.end(); it++)
 					{
 						LOG(*it);
 					}
 					break;
 				}
 				case INPUT :
 				{
 					// input line
 					string possibleIDInput;
 					getline(ss,possibleIDInput,';'); // get up to semicolon
 					if(regex_match(possibleIDInput, ID))	{
 						string inputID = removeWhitespace(possibleIDInput);
 						theDesign->add_pi(inputID);
 						Net *netfound = theDesign->add_find_net(inputID);
 						LOG("Got input:");
 						LOG(inputID);
 					}
 					
 					break;
 				}
 				case OUTPUT :
 				{
 					// output line
 					string possibleIDOutput;
 					getline(ss,possibleIDOutput,';'); // get up to semicolon
 					if(regex_match(possibleIDOutput, ID))	{
 						string outputID = removeWhitespace(possibleIDOutput);
 						theDesign->add_po(outputID);
 						Net *netfound = theDesign->add_find_net(outputID);
 						LOG("Got output:");
 						LOG(outputID);
 					}
 					
 					break;
 				}
 				case WIRE :
 				{
 					// wire line
 					string possibleIDWire;
 					getline(ss,possibleIDWire,';'); // get up to semicolon
 					if(regex_match(possibleIDWire, ID))	{
 						string wireID = removeWhitespace(possibleIDWire);
 						Net *netfound = theDesign->add_find_net(wireID);
 						LOG("Got wire:");
 						LOG(wireID);
 					}
 									
 					break;
 				}
 				case GATE :
 				{
 					// gate line
 					string possibleGateInfo;
 					getline(ss,possibleGateInfo,'('); // get up to the port list stuff
 					gateInfo(firsttoken, possibleGateInfo, &gate);
 					
 					vector<string> currentGatePuts;
 					vector<string>::iterator it;
 					string possiblePorts;
 					getline(ss,possiblePorts, ')');
 					parenParser(&currentGatePuts,possiblePorts);
 					// create the gate here
 					if(firsttoken == "and")	{
 						Gate *gatefound = theDesign->add_find_gate(AND,gate.at(1), atoi(gate.at(2).c_str()));
 						try	{
 							gatefound->addOutput(theDesign->find_net(currentGatePuts.front()));
 							LOG("output:");
 							LOG(currentGatePuts.front());
 						} catch(range_error &ex)	{
 							string out;
 							stringstream ss;
 							ss << lineNum;
 							out = ss.str();
 							ERROR("On line " << out << " " << ex.what());
 							throw runtime_error("Syntax error");
 						}
 						LOG("inputs:");
 						for(it=currentGatePuts.begin()+1;it < currentGatePuts.end(); it++)
 						{
 							LOG(*it);
 							try	{
 								gatefound->addInput(theDesign->find_net(*it));
 							} catch(range_error &ex)	{
 								string out;
 								stringstream ss;
 								ss << lineNum;
 								out = ss.str();
 								ERROR("On line " << out << " " << ex.what());
 								throw runtime_error("Syntax error");
 							}
 						}
 					}
 					else if(firsttoken == "or")	{
 						Gate *gatefound = theDesign->add_find_gate(OR,gate.at(1), atoi(gate.at(2).c_str()));
 						try	{
 							gatefound->addOutput(theDesign->find_net(currentGatePuts.front()));
 							LOG("output:");
 							LOG(currentGatePuts.front());
 						} catch(range_error &ex)	{
 							string out;
 							stringstream ss;
 							ss << lineNum;
 							out = ss.str();
 							ERROR("On line " << out << " " << ex.what());
 							throw runtime_error("Syntax error");
 						}
 						LOG("inputs:");
 						for(it=currentGatePuts.begin()+1;it < currentGatePuts.end(); it++)
 						{
 							LOG(*it);
 							try	{
 								gatefound->addInput(theDesign->find_net(*it));
 							} catch(range_error &ex)	{
 								string out;
 								stringstream ss;
 								ss << lineNum;
 								out = ss.str();
 								ERROR("On line " << out << " " << ex.what());
 								throw runtime_error("Syntax error");
 							}
 						}
 					}
 					else if(firsttoken == "nand")	{
 						Gate *gatefound = theDesign->add_find_gate(NAND,gate.at(1), atoi(gate.at(2).c_str()));
 						try	{
 							gatefound->addOutput(theDesign->find_net(currentGatePuts.front()));
 							LOG("output:");
 							LOG(currentGatePuts.front());
 						} catch(range_error &ex)	{
 							string out;
 							stringstream ss;
 							ss << lineNum;
 							out = ss.str();
 							ERROR("On line " << out << " " << ex.what());
 							throw runtime_error("Syntax error");
 						}
 						LOG("inputs:");
 						for(it=currentGatePuts.begin()+1;it < currentGatePuts.end(); it++)
 						{
 							LOG(*it);
 							try	{
 								gatefound->addInput(theDesign->find_net(*it));
 							} catch(range_error &ex)	{
 								string out;
 								stringstream ss;
 								ss << lineNum;
 								out = ss.str();
 								ERROR("On line " << out << " " << ex.what());
 								throw runtime_error("Syntax error");
 							}
 						}
 					}
 					else if(firsttoken == "nor")	{
 						Gate *gatefound = theDesign->add_find_gate(NOR,gate.at(1), atoi(gate.at(2).c_str()));
 						try	{
 							gatefound->addOutput(theDesign->find_net(currentGatePuts.front()));
 							LOG("output:");
 							LOG(currentGatePuts.front());
 						} catch(range_error &ex)	{
 							string out;
 							stringstream ss;
 							ss << lineNum;
 							out = ss.str();
 							ERROR("On line " << out << " " << ex.what());
 							throw runtime_error("Syntax error");
 						}
 						LOG("inputs:");
 						for(it=currentGatePuts.begin()+1;it < currentGatePuts.end(); it++)
 						{
 							LOG(*it);
 							try	{
 								gatefound->addInput(theDesign->find_net(*it));
 							} catch(range_error &ex)	{
 								string out;
 								stringstream ss;
 								ss << lineNum;
 								out = ss.str();
 								ERROR("On line " << out << " " << ex.what());
 								throw runtime_error("Syntax error");
 							}
 						}
 					}
 					else if(firsttoken == "xor")	{
 						Gate *gatefound = theDesign->add_find_gate(XOR,gate.at(1), atoi(gate.at(2).c_str()));
 						try	{
 							gatefound->addOutput(theDesign->find_net(currentGatePuts.front()));
 							LOG("output:");
 							LOG(currentGatePuts.front());
 						} catch(range_error &ex)	{
 							string out;
 							stringstream ss;
 							ss << lineNum;
 							out = ss.str();
 							ERROR("On line " << out << " " << ex.what());
 							throw runtime_error("Syntax error");
 						}
 						LOG("inputs:");
 						for(it=currentGatePuts.begin()+1;it < currentGatePuts.end(); it++)
 						{
 							LOG(*it);
 							try	{
 								gatefound->addInput(theDesign->find_net(*it));
 							} catch(range_error &ex)	{
 								string out;
 								stringstream ss;
 								ss << lineNum;
 								out = ss.str();
 								ERROR("On line " << out << " " << ex.what());
 								throw runtime_error("Syntax error");
 							}
 						}
 					}
 					else if(firsttoken == "not")	{
 						Gate *gatefound = theDesign->add_find_gate(NOT,gate.at(1), atoi(gate.at(2).c_str()));
 						try	{
 							gatefound->addOutput(theDesign->find_net(currentGatePuts.front()));
 							LOG("output:");
 							LOG(currentGatePuts.front());
 						} catch(range_error &ex)	{
 							string out;
 							stringstream ss;
 							ss << lineNum;
 							out = ss.str();
 							ERROR("On line " << out << " " << ex.what());
 							throw runtime_error("Syntax error");
 						}
 						LOG("inputs:");
 						for(it=currentGatePuts.begin()+1;it < currentGatePuts.end(); it++)
 						{
 							LOG(*it);
 							try	{
 								gatefound->addInput(theDesign->find_net(*it));
 							} catch(range_error &ex)	{
 								string out;
 								stringstream ss;
 								ss << lineNum;
 								out = ss.str();
 								ERROR("On line " << out << " " << ex.what());
 								throw runtime_error("Syntax error");
 							}
 						}
 					}
 					else	{
 			      WARN("Unrecognized token");
 					}
 					break;
 				}
 				case END :
 				{
 					// done!
 			    LOG("Done!");
 					break;
 				}
 				case ERROR :
 				{
 					// error...
 					string out;
 					stringstream ss;
 					ss << lineNum;
 					out = ss.str();
 			    ERROR("Line read error on line " << out);
 					break;
 				}
			}
		} catch(runtime_error &ex)	{
			ERROR(ex.what());
		}
	}
	ifile.close();
	return theDesign;
}

int lineType(string identifier) // going line by line, so decide what kind of line this is
{

	if(identifier == "//")
	{
		return COMMENT;
	}
	else if(identifier == "module")
	{
		return MODULE;
	}
	else if(identifier == "input")
	{
		return INPUT;
	}
	else if(identifier == "output")
	{
		return OUTPUT;
	}
	else if(identifier == "wire")
	{
		return WIRE;
	}
	else if((identifier == "and") | (identifier == "or") | (identifier == "nand") | (identifier == "nor") | (identifier == "xor") | (identifier == "not"))
	{
		return GATE;
	}
	else if(identifier == "endmodule")
	{
		return END;
	}
	else if((identifier == " ") | (identifier == "\n") | (identifier == "\t") | (identifier == ""))
	{
		return BLANK;
	}
	else
	{
		return ERROR;
	}
}

void parenParser(vector<string>* ports, string input)
{
	stringstream ss(input);
	while(ss.good()) // runs last time when eof bit is set!
	{
		string port;
		getline(ss, port, ',');
		port = removeWhitespace(port);
		ports->push_back(port);
	}
}

void gateInfo(string type, string info, vector<string> *gate)
{
	// looking for type of gate and delay info (if there) and gate name
	LOG("Getting gate info:");
	stringstream ss(info);
	string delay, name, temp;
	ss >> temp;
	temp = removeWhitespace(temp);
	if(temp[0] == '#')	{  // a gate delay is defined!!
		ss >> name;
		temp.erase(temp.begin());
		delay = temp;
		type = removeWhitespace(type);
		name = removeWhitespace(name);
		LOG(type);
		LOG(name);
		LOG(delay);
		gate->push_back(type);
		gate->push_back(name);
		gate->push_back(delay);
	}
	else	{
		type = removeWhitespace(type);
		name = removeWhitespace(temp);
		LOG(type);
		LOG(name);
		gate->push_back(type);
		gate->push_back(name);
		gate->push_back("0");
	}
}

bool regex_match(string target, string pattern)
{
    int status;
    regex_t re;
    	
    if (regcomp(&re, pattern.c_str(), REG_EXTENDED|REG_NOSUB) != 0) {
		return false;
    }
    status = regexec(&re, target.c_str(), (size_t) 0, NULL, 0);
    regfree(&re);
    if (status != 0) {
        return false;      /* no match */
    }
	
	// Matches
    return true;
}

string removeWhitespace(string str)
{
	//LOG("Started removing whitespace");
	str.erase(remove_if(str.begin(), str.end(), ::isspace), str.end());
	return str;
}