/*
    将键值对key-value封装成一个类entry,并将所有entry放入数组，这样每个Entry都具有唯一的索引，为了建立key和索引之间的映射关系，使用hash函数
*/

struct Entry
{
    public:
        int key;
        string val;
        Entry(int key, string val){
            this->key = key;
            this->val = val;
        }
};
class Entry{
private:
    int key;
    string val;
public:
    Entry(int key_, string val_):key(key_), val(val_){}  
}
// 基于数组实现简单的哈希表
class ArrayHashMap
{
private:
    vector<Entry*> buckets;
public:
    ArrayHashMap(){
        buckets = vector<Entry*>(100);
    };
    ~ArrayHashMap(){
        //释放内存
        for(const auto& bucket : buckets){
            delete bucket;
        }
        buckets.clear();
    }
    // 哈希函数
    int hashFunc(int key){
        int index = key % 100;
        return index;
    }

    // 查询操作
    string get(int key){
        int index = hashFunc(key);
        Entry *pair = buckets[index];
        if(pair == nullptr)
            return nullptr;
        return pair->val;
    }

    // 添加操作
    void put(int key, string val){
        Entry* pair = new Entry(key, val);
        int index = hashFunc(key);
        buckets[index] = pair;
    }

    // 删除操作
    void remove(int key){
        int index = hashFunc(key);
        // 释放内存并置为nullptr
        delete buckets[index];
        buckets[index] = nullptr;
    }

    // 获取所有键值对
    vector<Entry*> entrySet(){
        vector<Entry*> entrySet;
        for(Entry* pair : buckets){
            if(pair != nullptr)
                entrySet.push_back(pair);
        }
        return entrySet;
    }

    // 获取所有键
    vector<int> keySet(){
        vector<int> keySet;
        for(Entry* pair : buckets){
            if(pair != nullptr)
                keySet.push_back(pair->key);
        }
        return keySet;
    }

    // 获取所有值
    vector<string> valueSet(){
        vector<string> valueSet;
        for(Entry* pair : buckets){
            if(pair != nullptr)
                valueSet.push_back(pair->val);
        }
        return valueSet;
    }

    void print(){
        for(Entry* kv : entrySet()){
            cout << kv->key << " " << kv->value << endl;
        }
    }
};
