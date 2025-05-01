#include <iostream>
#include <string>
#include <fstream>
#include <sstream>

using namespace std;

class Product{
protected:
    string _id;
    string _title;
    string _seller;
    double _price;
public:
    Product(string id, string title, string seller, double price):_id(id), _title(title), _seller(seller), _price(price){}
    virtual void display() const = 0;
    virtual string getType() const = 0;
    virtual void savefile() const = 0;
    virtual ~Product();
}

class GameItem : public Product {
private:
    int _level;
    Rarity _rarity;
    string getRarity(){
        if(_rarity == Rarity::Common) return "Common";
        else if(_rarity == Rarity::Rare) return "Rare";
        else if(_rarity == Rarity::Legendary) return "Legendary";
        else return "None";
    }
public:
    enum class Rarity{None, Common, Rare, Legendary}
    GameItem(string id, string title, string seller, double price, int level, GameItem::Rarity rarity)
        :Product(id, title, seller, price), _level(level), _rarity(rarity){}
    void display() const override{
        cout<<"ID: "<<_id<<"\n"
        <<"TYPE: Game item \n"
        <<"TITLE: "<<_title<<"\n"
        <<"Seller: "<<_seller<<"\n"
        <<"Price: "<<_price<<"\n"
        <<"Level: "<<_level<<"\n"
        <<"Rarity: "<<getRarity()<<"\n"
    }
    string getType() const override{
        return "GameItem";
    };
    void savefile() const override{
        //Todo
    }

};

class Blueprint : public Product {
private:
    Format _format;
    int _pages;
    string getFormat(){
        if(_format == Format::PDF) return "PDF";
        else if(_format == Format::DWG) return "DWG";
        else return "None";
    }
public:
    enum class Format {None, PDF, DWG};
    Blueprint(string id, string title, string seller, double price, Blueprint::Format format, int pages)
    :Product(id, title, seller, price), _format(format), _pages(pages){}
    void display() const override{
        cout<<"ID: "<<_id<<"\n"
        <<"TYPE: Blueprint \n"
        <<"TITLE: "<<_title<<"\n"
        <<"Seller: "<<_seller<<"\n"
        <<"Price: "<<_price<<"\n"
        <<"Format: "<<getFormat()<<"\n"
        <<"Pages: "<<_pages<<"\n"
    }
    string getType() const override{
        return "Blueprint";
    }
    void savefile() const override{
        //Todo
    }
};

class Service : public Product {
private:
    string _duration;
    Category _category;
    string getCategory(){
        if(_category == Category::Gaming) return "Gaming";
        else if(_category == Category::Design) return "Design";
    }
public:
    enum class Category {Gaming, Design};
    Service(string id, string title, string seller, double price, string duration, Service::Category category)
    :Product(id, title, seller, price), _duration(duration), _category(category){}
    void display() const override{
        cout<<"ID: "<<_id<<"\n"
        <<"TYPE: Service \n"
        <<"TITLE: "<<_title<<"\n"
        <<"Seller: "<<_seller<<"\n"
        <<"Price: "<<_price<<"\n"
        <<"Duration: "<<_duration<<"\n"
        <<"Category: "<<getCategory()<<"\n"
    }
    string getType() const override{
        return "Service";
    }
    void savefile() const override{
        //Todo
    }
};

class Marketplace {
private:
    vector<Product*> products;
public:
    void loadFromFile(){
        ifstream in_file(".\\file\\market_trade.txt", ios::in);
        if(in_file.fail()){
            cout<<"fail to open the file.\n";
            return;
        }
        string line;
        while(getline(in_file, line)){
            istringstream iss(line);
            string id, type, title, seller;
            double price
            iss >> id >> type >> title >> seller;
            if(type == "GameItem"){
                int level;
                string rarity;
                GameItem::Rarity new_rarity;
                iss >> level >> rarity;
                if(rarity == "Common") new_rarity == GameItem::Rarity::Common;
                else if(rarity == "Rare") new_rarity == GameItem::Rarity::Rare;
                else if(rarity == "Legendary") new_rarity == GameItem::Rarity::Legendary;
                Product newproduct = new GameItem(id, title, seller, price, level, new_rarity);
            }
            else if(type == "Blueprint"){
                
            }
            else if(type == "Service"){

            }
        }
    } // 读取所有商品信息
    void displayAll() const;
    void exportByType(const string& type, const string& filename) const;
    friend class ProductStatistics; // 友元类，用于分析
    ~Marketplace();
};

class ProductStatistics {
public:
    static void analyzeBySeller(const Marketplace& m, const string& seller);
    static void mostExpensive(const Marketplace& m);
};
