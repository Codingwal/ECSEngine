namespace ECSEngine
{
    template <typename T>
    inline void JSONSerializer::Serialize(const T &data)
    {
        file << "{\n";
        data.Serialize(*this);
        file.seekp(file.tellp() - 2); // Remove last comma
        file << "\n}";
    }
    template <typename T>
    inline void JSONSerializer::Serialize(const std::string &key, const T &value)
    {
        file << "\"" << key << "\": ";
        Serialize(value);
        file << ",\n";
    }

    template <typename T>
    inline void JSONSerializer::Serialize(const std::vector<T> &data)
    {
        file << "[\n";
        for (const T &element : data)
        {
            Serialize(element);
            file << ",\n";
        }
        file.seekp(file.tellp() - 2); // Remove last comma
        file << "\n]";
    }
}