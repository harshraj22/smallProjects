
# specify database configurations
config = {
    'host': 'db-mysql',
    'port': 3306,
    'user': 'root',
    'password': 'mypassword',
    'database': 'DB'
}
db_user = config.get('user')
db_pwd = config.get('password')
db_host = config.get('host')
db_port = config.get('port')
db_name = config.get('database')
# specify connection string


import pymysql.cursors
# https://github.com/PyMySQL/PyMySQL/

# Connect to the database
connection = pymysql.connect(host=db_host,
                             user=db_user,
                             password=db_pwd,
                             database=db_name,
                             cursorclass=pymysql.cursors.DictCursor)

with connection:
    # with connection.cursor() as cursor:
    #     # Create a new record
    #     sql = "INSERT INTO `users` (`email`, `password`) VALUES (%s, %s)"
    #     cursor.execute(sql, ('webmaster@python.org', 'very-secret'))

    # # connection is not autocommit by default. So you must commit to save
    # # your changes.
    # connection.commit()

    with connection.cursor() as cursor:
        # Read a single record
        sql = "SELECT * FROM Occurrences;"
        cursor.execute(sql)
        result = cursor.fetchone()
        result = cursor.fetchall()
        print(result)