#include <iostream>
#include <string>

// 抽象组件 - 数据源
class DataSource {
public:
    virtual ~DataSource() = default;
    virtual void writeData(const std::string& data) = 0;
    virtual std::string readData() = 0;
};

// 具体组件 - 标准输入数据源
class StdDataSource: public DataSource {
public:
    void writeData(const std::string& data) override {
        // TODO
        std::cout<<data<<std::endl;
    }

    std::string readData() override {
        // TODO
        std::string input = "";
        std::cin >> input;
        return input;
    }
};

// 装饰器基类
class DataSourceDecorator: public DataSource {
protected:
    DataSource* wrappee;
public:
    explicit DataSourceDecorator(DataSource* source) : wrappee(source) {}
    virtual ~DataSourceDecorator() { delete wrappee; }
};

// 具体装饰器 - 加密
class EncryptionDecorator: public DataSourceDecorator {
public:
    explicit EncryptionDecorator(DataSource* source): DataSourceDecorator(source) {}

    void writeData(const std::string& data) override {
        // TODO
        std::string newdata = "ENCRYPTED(" + data + ")";
        wrappee->writeData(newdata);
    }

    std::string readData() override {
        // TODO
        std::string data = wrappee->readData();
        return data.substr(10, data.size() - 11);
    }
};

// 具体装饰器 - 压缩
class CompressionDecorator: public DataSourceDecorator {
public:
    explicit CompressionDecorator(DataSource* source): DataSourceDecorator(source) {}

    void writeData(const std::string& data) override {
        // TODO
        std::string newdata = "COMPRESSED[" + data + "]";
        wrappee->writeData(newdata);
    }

    std::string readData() override {
        // TODO
        std::string data = wrappee->readData();
        return data.substr(11, data.size() - 12);
    }
};

int main(){
    // 创建基础实例
    DataSource *source = new StdDataSource();
    // 为实例添加新的功能，先加密后压缩
    source = new EncryptionDecorator(new CompressionDecorator(source));
    // 使用修饰后的实例
    std::string content = source->readData();
    source->writeData("data");
}