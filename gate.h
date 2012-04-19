#ifndef GATE_H
#define GATE_H

#include <vector>
#include <string>
#include "net.h"
#include "global.h"

using namespace std;

// forward declaration
class Net;

enum {AND, OR, NAND, NOR, XOR, NOT};

class Gate {
 public:
  Gate();
  Gate(string n, int d);
  virtual ~Gate() {
    LOG("Dto");
  }

  virtual char eval() = 0;
  virtual void dump(ostream &os) = 0;
  string name();
  void addInput(Net *n);
  void addOutput(Net *n);
  vector<Net *> *getInputs();
  Net* getOutput();
  int getNumInputs();
  int getDelay();
 protected:
  vector<Net *> *inputs;
  Net *output;
  string inst_name;
  int delay;
  
protected:
  void dumpNetList(ostream &os);
};

class And : public Gate {
 public:
  And();
  And(string n, int d);
  ~And() { Gate::~Gate(); }
  char eval();
  void dump(ostream &os);
};

class Or : public Gate {
 public:
  Or();
  Or(string n, int d);
  ~Or() { Gate::~Gate(); }
  char eval();
  void dump(ostream &os);
};

class Nor : public Gate {
 public:
  Nor();
  Nor(string n, int d);
  ~Nor() { Gate::~Gate(); }
  char eval();
  void dump(ostream &os);
};

class Nand : public Gate {
 public:
  Nand();
  Nand(string n, int d);
  ~Nand() { Gate::~Gate(); }
  char eval();
  void dump(ostream &os);
};

class Xor : public Gate {
 public:
  Xor();
  Xor(string n, int d);
  ~Xor() { Gate::~Gate(); }
  char eval();
  void dump(ostream &os);
};

class Not : public Gate {
 public:
  Not();
  Not(string n, int d);
  ~Not() { Gate::~Gate(); }
  char eval();
  void dump(ostream &os);
};

#endif
