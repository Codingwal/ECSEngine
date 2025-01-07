namespace ECSEngine
{
    template <typename T>
    inline void JSONSerializer::Serialize(const T &data)
    {
        file << "{";
        data.Serialize(*this);
        file.seekp(file.tellp() - 1); // Remove last comma
        file << "}";
    }
    template <typename T>
    inline void JSONSerializer::Serialize(const std::string &key, const T &value)
    {
        file << "\"" << key << "\":";
        Serialize(value);
        file << ",";
    }

    template <typename T>
    inline void JSONSerializer::Serialize(const std::vector<T> &data)
    {
        file << "[";
        for (const T &element : data)
        {
            Serialize(element);
            file << ",";
        }
        file.seekp(file.tellp() - 1); // Remove last comma
        file << "]";
    }
}