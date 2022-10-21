
// #include <MySQL_Connection.h>
// #include <MySQL_Cursor.h>
// #include <MySQL_Encrypt_Sha1.h>
// #include <MySQL_Packet.h>


// byte mac_addr[] = { 0xDE, 0xAD, 0xBE, 0xEF, 0xFE, 0xED};

// // IPAddress server_addr( 35, 74, 75, 58 );

// char hostname[] = "database.cvemvsnnhti1.ap-northeast-1.rds.amazonaws.com";

// char user[] = "user4";
// char password[] = "12345678";

// char INSERT_SQL[] = 
// "INSERT INTO AWS_Mysql.test (Num,Data)VALUES('1', '100')";

// EthernetClient client;
// MySQL_Connection conn((Client *)&client);

// void setup() {
//     Serial.begin(9600);
//     while (!Serial);
//     Ethernet.begin(mac_addr);
//     Serial.println("연결중...");
//     if (conn.connect(server_addr, 3306, user, password)) {
//         delay(1000);
//     }
//     else
//     Serial.println("응 연결 안됐어~");
// }

// void loop()
// {
//     delay(2000);

//     Serial.println("데이터 기록함");

//     MySQL_Cursor *cur_mem = new MySQL_Cursor(&conn);
//     cur_mem->execute(INSERT_SQL);
//     delete cur_mem;
// }