#include <iostream>
#include "trie.h"

TrieNode::TrieNode() {
    // TODO
    val = ' ';
    isend = false;
}
TrieNode::TrieNode(char v) {
    // TODO
    val = v;
    isend = false;
}
TrieNode::~TrieNode() {
    // TODO
    if(child.size() != 0)
    {
        for(auto i : child)
        {
            delete i;
        }
    }
    val = ' ';
    isend = false;
    std::cout<<"~TrieNode!\n";
}
Trie::Trie() {
    // TODO
    root = new TrieNode();
}
Trie::~Trie() {
    // TODO
    delete root;
}
void Trie::Insert(std::string st) {
    // TODO
    TrieNode *start = root;
    TrieNode *search = start;
    int loc = 0;
    do
    {
        if(loc == st.size())
        {
            start->isend = true;
            break;
        }
        for(auto i : start->child)
        {
            if(i->val == st[loc])
            {
                search = i;
                break;
            }
        }
        if(search == start)
        {
            break;
        }
        loc++;
        start = search;
    }
    while(1);
    while(loc < st.size())
    {
        start->child.push_back(new TrieNode(st[loc++]));
        if(loc == st.size())
        {
            start->child[start->child.size() - 1]->isend = true;
        }
        start = start->child[start->child.size() - 1];
    }
}
bool Trie::Lookup(std::string st) {
    // TODO
    TrieNode *start = root;
    TrieNode *search = start;
    int loc = 0;
    bool judge = false;
    while(loc < st.size())
    {
        judge = false;
        for(auto i : start->child)
        {
            if(i->val == st[loc])
            {
                search = i;
                judge = true;
                break;
            }
        }
        if(judge == false)
        {
            break;
        }
        else
        {
            loc++;
            start = search;
        }
    }
    if(judge && start->isend == true) return true;
    else return false;
}

int Trie::Count(TrieNode *start)
{
    int num = 0;
    if(start->isend)
    {
        num++;
    }
    for(auto i : start->child)
    {
        num += Count(i);
    }
    return num;
}

int Trie::Prefix(std::string st) {
    // TODO
    if(st.size() == 0)
    {
        return Count(root);
    }
    TrieNode *start = root;
    TrieNode *search = start;
    int loc = 0;
    bool judge = false;
    while(loc < st.size())
    {
        judge = false;
        for(auto i : start->child)
        {
            if(i->val == st[loc])
            {
                search = i;
                judge = true;
                break;
            }
        }
        if(judge == false)
        {
            break;
        }
        else
        {
            loc++;
            start = search;
        }
    }
    if(judge) 
    {
        return Count(start);
    }
    else return 0;
}

int main() {
    Trie* trie = new Trie;
    trie->Insert("apple");
    trie->Insert("app");
    trie->Insert("april");
    trie->Insert("banana");
    trie->Insert("band");
    std::cout << trie->Prefix("a") << std::endl;    // 输出 3 (["apple", "app", "april"])
    std::cout << trie->Prefix("ap") << std::endl;   // 输出 3 (["apple", "app", "april"])
    std::cout << trie->Prefix("app") << std::endl;  // 输出 2 (["apple", "app"])
    std::cout << trie->Prefix("appl") << std::endl; // 输出 1 (["apple"])
    std::cout << trie->Prefix("ban") << std::endl;  // 输出 2 (["banana", "band"])
    std::cout << trie->Prefix("bana") << std::endl; // 输出 1 (["banana"])
    std::cout << trie->Prefix("bandit") << std::endl; // 输出 0: 没有任何以 "bandit" 开头的单词
    delete trie;
    return 0;
}
