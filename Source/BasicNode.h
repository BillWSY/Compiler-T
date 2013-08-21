#ifndef BASICNODE_H_
#define BASICNODE_H_

#include "ClassEnum.h"

class BasicNode {
  private:
      IDType id;
      static IDType idCnt;
      static IDType nodeCnt;
      NodeType nodeType;
  protected:
      BasicNode(NodeType nType) {
          id = idCnt ++;
          ++ nodeCnt;
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
          -- nodeCnt;
      }
      static int nodeCount() {
          return nodeCnt;
      }
};

#endif // BASICNODE_H_
