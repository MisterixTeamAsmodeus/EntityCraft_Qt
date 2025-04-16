#include <EntityCraft_Qt/entitycraft-qt.h>

#include <QStack>

template<typename Container, typename Type>
void test_type(std::vector<Type> test_data)
{
    EntityCraft::RelationInserter<Container, Type> inserter;
    Container container;
    inserter.insertInRelationProperty(container, test_data);
    assert(container.size() == test_data.size());
}

int main()
{
    test_type<QStack<int>>(std::vector<int>{ 1, 2, 3 });
    test_type<QVector<int>>(std::vector<int>{ 1, 2, 3 });
    test_type<QStringList>(std::vector<QString>{ "1", "2", "3" });
}
