#include"dbi_mysql.h"
#include <iostream>
using namespace std;
int main()
{
    DBI_mysql echo_mysql;
    char sql[] = "select * from user";

    if(echo_mysql.db_connect("localhost", "chatting", "root", "lz1258", 0) != DBI_SUCCESS)
    {
        echo_mysql.db_get_err_msg();
        exit(-1);
    }

    if(echo_mysql.db_begin() != DBI_SUCCESS)
    {
        echo_mysql.db_get_err_msg();
        exit(-1);
    }
    
    if(echo_mysql.db_execute(sql) != DBI_SUCCESS)
    {
        echo_mysql.db_get_err_msg();
        exit(-1);
    }

    if(echo_mysql.db_res() != DBI_SUCCESS)
    {
        echo_mysql.db_get_err_msg();
        exit(-1);
    }
    
    char buf[10];
    int columns = 0;
    
    dbi_prepare_t echo_prepare;
    if(echo_mysql.db_prepare_sql(&echo_prepare, sql) != DBI_SUCCESS)
    {
        echo_mysql.db_get_err_msg();
        exit(-1);
    }

    if((columns = echo_mysql.db_get_outcolumns(&echo_prepare)) == DBI_ERROR)
    {
        echo_mysql.db_get_err_msg();
        exit(-1);
    }

    while(echo_mysql.db_fetch() == true)
    {
        for(int i = 0; i < columns; ++ i)
        {
            if(echo_mysql.db_get_field(i, buf, 0) != DBI_SUCCESS)
            {
                echo_mysql.db_get_err_msg();
                exit(-1);
            }
            else
            {
                cout<<buf<<" ";
            }
        }
        cout<<endl;
    }

    echo_mysql.db_close_cursor();
    echo_mysql.db_disconnect();

    return 0;

}

