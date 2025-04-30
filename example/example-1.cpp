#include <EntityCraft_Qt/entitycraft-qt.h>

#include <QDateTime>
#include <QUuid>

#include <iostream>

/// Этот пример проверяет работоспосбность класса NullCheker для корректного определения, что поле равно NULL

/// Функция test_type принимает аргумент типа Type и возвращает значение типа bool,
/// проверяя, является ли переданный аргумент нулевым с помощью функции EntityCraft::NullCheker.

/// В функции main вызываются утверждения (assert) для проверки каждого типа данных: QDate, QDateTime, QUuid и QString.
/// Затем проверяются обратные случаи, когда переданные значения не являются нулевыми,
/// чтобы убедиться, что функция test_type работает корректно.

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
