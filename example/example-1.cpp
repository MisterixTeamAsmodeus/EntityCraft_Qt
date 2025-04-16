#include <EntityCraft_Qt/entitycraft-qt.h>

#include <QDateTime>
#include <QUuid>

#include <iostream>

template<typename Type>
bool test_type(const Type& start_value)
{
    auto type_converter = EntityCraft::NullCheker<Type>();
    return type_converter.isNull(start_value);
}

int main()
{
    assert(test_type(QDate()));
    assert(test_type(QDateTime()));
    assert(test_type(QUuid()));
    assert(test_type(QString()));

    assert(!test_type(QDate::currentDate()));
    assert(!test_type(QDateTime::currentDateTime()));
    assert(!test_type(QUuid::createUuid()));
    assert(!test_type(QString("test_value")));
}
