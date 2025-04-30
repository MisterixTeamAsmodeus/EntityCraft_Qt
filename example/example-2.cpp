#include <EntityCraft_Qt/entitycraft-qt.h>

#include <QStack>

/// Этот пример проверяет работоспосбность класса RelationInserter для обобщенного взаимодействия с масивами и подобными структурами

/// Этот код содержит шаблонную функцию test_type,
/// которая принимает вектор элементов типа Type и вставляет их в контейнер типа Container.
/// Функция main вызывает функцию test_type для проверки различных типов контейнеров и их содержимого.

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
    test_type<QStack<int>>(std::vector<int> { 1, 2, 3 });
    test_type<QVector<int>>(std::vector<int> { 1, 2, 3 });
    test_type<QStringList>(std::vector<QString> { "1", "2", "3" });
}
