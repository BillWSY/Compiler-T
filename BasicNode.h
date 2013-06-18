#ifndef BASICNODE_H_
#define BASICNODE_H_

#include "ASTClass.h"
#include "ClassEnum.h"

class BasicNode {
  private:
      IDType id;
      static IDType idCnt;
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
      virtual ~BasicNode() {
          if (id == idCnt) -- idCnt;
      }
      static int nodeCount() {
          return idCnt;
      }
};

#endif // BASICNODE_H_
