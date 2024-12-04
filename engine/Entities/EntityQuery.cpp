#include "EntityQuery.hpp"

// EntityQuery::Iterator()
//     : archetypeIndex(-1), indexInArchetype(-1)
// {
// }
// EntityQuery::Iterator(std::vector<Archetype &> _archetypes)
//     : archetypes(_archetypes), archetypeIndex(0), indexInArchetype(0)
// {
// }
// EntityQuery::Iterator EntityQuery::Iterable::begin()
// {
//     return Iterator(archetypes);
// }

// EntityQuery::Iterator EntityQuery::Iterable::end()
// {
//     return Iterator();
// }

// EntityQuery::Iterator EntityQuery::Iterator::operator++()
// {
//     indexInArchetype++;
//     if (indexInArchetype >= archetypes[archetypeIndex].EntityCount())
//     {
//         archetypeIndex++;
//         if (archetypeIndex >= archetypes.size())
//         {
//             archetypeIndex = -1;
//             indexInArchetype = -1;
//         }
//     }
//     return *this;
// }
