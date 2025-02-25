#include<iostream>
using namespace std;

class Animal{
protected:
    string name;
public:
    Animal(string a){
        name = a;
    }
    void animalprop(){
        cout<<name<<" is one of many eukaryotic multicellular heterotrophic organisms without wall for cells"<<endl;
    }
};

class Mammal : public Animal{
public:
    Mammal(string a) : Animal(a){}
    void mammalProp(){
        cout<<name<<" is a warm-blooded animal with hair or fur on its skin and has 4 limbs. An important point about "<<name<<" is that it feeds on its mother's milk when young"<<endl;
    }
};

class Herbivore : public Animal{
public:
    Herbivore(string a) : Animal(a){}
    void herbivoreProp(){
        cout<<name<<" eats only plants and plant-based edible elements. Due to this diet, "<<name<<" also has a longer small intestine unlike carnivores"<<endl;
    }
};

class Cow : public Mammal, public Herbivore{
public:
    Cow(string a) : Mammal(a), Herbivore(a){}
    void cowProp(){
        string name = Mammal::name;
        cout<<name<<" is a Bovine creature, mostly known for supply of Milk and other Dairy products. "<<name<<" has cloven hooves and horns. "<<name<<"'s digestive system involves the process of rumination, where it regurgigates partially digested food from its rumen, and rechews and reswallows it"<<endl;
        cout<<"Moo!! ~said "<<name<<endl;
    }
};

int main(){
    Cow C("Ushi");
    C.Mammal::animalprop();
    C.herbivoreProp();
    C.mammalProp();
    C.cowProp();
    return 0;
}