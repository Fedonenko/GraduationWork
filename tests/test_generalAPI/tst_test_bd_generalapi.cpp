#include <QtTest>

// add necessary includes here

class test_bd_generalAPI : public QObject
{
    Q_OBJECT

public:
    test_bd_generalAPI();
    ~test_bd_generalAPI();

private slots:
    void test_case1();

};

test_bd_generalAPI::test_bd_generalAPI()
{

}

test_bd_generalAPI::~test_bd_generalAPI()
{

}

void test_bd_generalAPI::test_case1()
{

}

QTEST_APPLESS_MAIN(test_bd_generalAPI)

#include "tst_test_bd_generalapi.moc"
