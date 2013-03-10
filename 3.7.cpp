/**
 * careercup 3.7
 * An animal shelter holds only dogs and cats, and operates on
 * a strictly ¡°first in, first out¡± basis. People must adopt either 
 * the ¡°oldest¡±(based on arrival time) of all animals at the shelter, 
 * or they can select whether they could prefer a dog or a cat 
 * (and will receive the oldest animal of that type). They cannot 
 * select which specific animal they would like. Create the data structures 
 * to maintain this system and implement operations such as enqueue, 
 * dequeueAny, dequeueDog and dequeueCat. You may use the built-in Linked
 * List data structure.
 */
#include <iostream>
#include <list>

using namespace std;

typedef enum _animal {
    Dog = 0,
    Cat,
    None    // this is special indicator
}animal;

class shelter {
private:
    list<animal> aslist;
public:
    shelter() { }
    
    /*
     * method: enqueue
     */ 
    void enqueue(animal input)
    {
        if ( input != None )
            aslist.push_back(input);
    }
    
    /*
     * method: dequeue_any
     */
    animal dequeue_any()
    {
        animal retval = aslist.front();
        aslist.pop_front();
        
        return retval;
    }
    
    /*
     * method: dequeue dog
     */
    animal dequeue_dog()
    {
        animal retval;
        list<animal>::iterator it = aslist.begin();
        
        while ( *it != Dog && it != aslist.end() ) 
            it++;
        if ( it == aslist.end() )
            return None;
            
        retval = *it;
        aslist.erase(it);
        
        return retval;
    }
    
    /*
     * method: dequeue cat
     */
    animal dequeue_cat()
    {
        animal retval;
        list<animal>::iterator it = aslist.begin();
        
        while ( *it != Cat && it != aslist.end() ) 
            it++;
        if ( it == aslist.end() )
            return None;
            
        retval = *it;
        aslist.erase(it);
        
        return retval;
    }
};

int main() 
{
    shelter mysh;
    
    for (int i = 0; i < 5; i++)
        mysh.enqueue(Dog);
    mysh.enqueue(Cat);
    
    cout << mysh.dequeue_any() << endl;
    cout << mysh.dequeue_dog() << endl;
    cout << mysh.dequeue_cat() << endl;
    
    return 0;
}
