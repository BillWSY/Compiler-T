#include "ClassTypeDef.h"

class BasicNode {
  private:
      IDType id;
      static idCnt = 0;
      NodeType nodeType;
  protected:
      BasicNode(NodeType nType) {
          id = idCnt ++;
          nodeType = nType;
      }
  public:
      IDType getID() {
          return id;
      }
      NodeType getType() {
          return nodeType;
      }
};

