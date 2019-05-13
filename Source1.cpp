#include <set>
class Node{
	friend class LRUCache;
	private:
	Node(): Node("", ""){}
	Node(std::string strKey, std::string strVal) : m_strKey(strKey), m_strVal(strVal)
		, m_pnext(NULL), m_ppre(NULL){}

	private:
	std::string m_strKey, m_strVal;//@mem m_strKey, m_strVal key/value string
	private:
	Node *m_ppre, *m_pnext;  //@mem m_ppre, m_pnext pointers pointing to previous/next node
};

class LRUCache{
	public:
	LRUCache(): LRUCache(10){}
	LRUCache(size_t nlimit): m_nlimit(nlimit), m_phead(NULL), m_pend(NULL){}

	void mfn_removeNode(){
	}
	void mfn_addNode(const std::string &strKey){
		//@para-pnode: append pnode to tail of this node list
		if(mfn_empty()){
			m_pend = pnode;
			m_phead = pnode;
		}
		else{
			pnode->m_ppre = m_pend;
			m_pend->m_pnext = pnode;
			m_pend = pnode;
		}
	}
	bool mfn_empty(){
		//@func-return whether the node list is empty or not
		return m_pend == m_phead;
	}
	private:
	std::set<Node> *m_nodeset;   //@mem-m_nodeset: point to node set in bottom cluster
	std::set<Node> m_nodecache; //@mem-m_nodecache: Node cache
	size_t m_nlimit;  //@mem-m_nlimit: limit of number of nodes in this cache
	Node *m_phead ,*m_pend; //@mem-m_phead, m_pend: node list header and ender
};

