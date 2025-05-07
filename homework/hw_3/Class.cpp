#include "Class.h"

void Class::add_function(const Function &f) {
    funcs.push_back(f);
}

void Class::inherit(const Class &c) {
    parent = &c;
}

bool call(CallSite cs) {
    const Class *curr_base = &cs.base;
    bool same_name = false;
    for(const Function &i : curr_base->funcs){
        if(i.name == cs.function_name){
            same_name = true;
            break;
        }
    }
    do{
        const Class *curr_arg = &cs.arg;
        while(curr_arg){
            Function f = {cs.function_name, *curr_arg};
            for(const Function &i : curr_base->funcs){
                if(f == i){
                    cout<<curr_base->get_name()<<"::"<<cs.function_name<<"("<<(*curr_arg).get_name()<<")"<<endl;
                    return true;
                }
            }
            curr_arg = curr_arg->parent;
        }
        curr_base = curr_base->parent;
    }
    while(curr_base && !same_name);
    cout<<"Function not found."<<endl;
    return false;
}

bool Class::is_ancestor(const Class &c) const {
    if(!parent) return false;
    if(*parent == c) return true;
    else{
        const Class *curr = parent;
        while(curr->parent){
            curr = curr->parent;
            if(*curr == c) return true;
        }
        return false;
    }
}