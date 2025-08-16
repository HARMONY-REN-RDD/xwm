```
u8 <- primitive datatype
u8 x <- datatype + variable, initialized to 0
u8 x = 5 <- datatype + variable + expression + literal

class Datatype {
  String name
  u64 size
}

class Variable {
  Datatype *type
  String name
  vector<u8> value
}

class Primitive : public Datatype;

class Aggregate : public Datatype {
  vector<Variable *> member_variables
  vector<...*> member_functions
}



```
