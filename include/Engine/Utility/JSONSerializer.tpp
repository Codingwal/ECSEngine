namespace ECSEngine
{
    template <typename T>
    inline void JSONSerializer::Serialize(T &data)
    {
        file << "{\n";
        data.Serialize(*this);
        file.seekp(file.tellp() - 2); // Remove last comma
        file << "\n}";
    }
    template <typename T>
    inline void JSONSerializer::Serialize(std::string key, T &value)
    {
        file << "\"" << key << "\": ";
        Serialize(value);
        file << ",\n";
    }
}