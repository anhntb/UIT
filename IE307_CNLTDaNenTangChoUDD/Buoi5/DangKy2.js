import { View, Text,TextInput,Button,StyleSheet,FlatList } from 'react-native'
import { useState } from 'react';
//Dùng Expo sqlite
import * as SQLite from 'expo-sqlite/legacy';
//Mở DataBase
const db = SQLite.openDatabase("qlbanhoap11.db")
export default function DangKy() {
    const [tendn,gantendn]=useState('');
    const[matkhau,ganmatkhau]=useState('');
    const[email,ganemail]=useState('');
    const[listnguoidung,ganlistnguoidung]=useState([]);
    //Tạo Bảng Người Dùng
    const taobangUser=()=>{
        db.transaction(function (txn) {  
          txn.executeSql(
            "SELECT name FROM sqlite_master WHERE type='table' AND name='tbluser'",
            [],
            function (tx, res) {
              if (res.rows.length == 0) {
                  txn.executeSql(
                  'CREATE TABLE IF NOT EXISTS tbluser(userid INTEGER PRIMARY KEY AUTOINCREMENT, username VARCHAR(200), password VARCHAR(255),email nvarchar(200) )',
                  []
                );
                alert('Tạo Bảng Thành Công');
              }
              else
              alert('Bảng đã có');
            })})}
    //Thêm Người Dùng
    const ThemNguoiDung=()=>{
        db.transaction(function (tx) {
          tx.executeSql(
            'INSERT INTO tbluser (username, password,email) VALUES (?,?,?)',
            [tendn,matkhau,email],
            (tx, results) => {
            alert('Thêm Thành Công ');
             
            }
          );
        });
      }
      //Lấy thông tin người dùng hiển thị ds
      const DocBangNguoiDung=()=>{
        db.transaction((tx) => {
            tx.executeSql(
              'SELECT * FROM tbluser',
              [],
              (tx, results) => {
                var temp = [];
                for (let i = 0; i < results.rows.length; ++i)
                  temp.push(results.rows.item(i));
                ganlistnguoidung(temp);
              }
            );
          });
      }
      const ItemView = ({item}) => {
        return (
          <View >
            <Text >{item.username}</Text>
          </View>
        );
      };
      const ItemSeparatorView = () => {
        return (
          <View
              style={{
                  height: 0.5,
                  width: '100%',
                  backgroundColor: '#C8C8C8'
              }}
          />
        );
      };
  return (
    <View>
      <Text>Tên Đăng Nhập</Text>
      <TextInput styles={styles.item} 
      value= {tendn} onChangeText={gantendn}/>
      <Text>Mật Khẩu</Text>
      <TextInput styles={styles.item} 
      secureTextEntry={true}
      value= {matkhau} onChangeText={ganmatkhau}
      />
      <Text>Email</Text>
      <TextInput styles={styles.item} 
      value= {email} onChangeText={ganemail}/>
      <Button title='Tạo Bảng' onPress={()=>{taobangUser()}}/>
      <Button title='Đăng Ký' onPress={()=>{ThemNguoiDung()}}/>
      <Button title='Đọc Bảng Người Dùng' onPress={()=>{DocBangNguoiDung()}}/>
      <FlatList
        data={listnguoidung}
        ItemSeparatorComponent={ItemSeparatorView}
        renderItem={ItemView}
        keyExtractor={(item, index) => index.toString()}
      />
    </View>
  )
}
const styles = StyleSheet.create({
    container: {
      justifyContent: 'center',
      flex: 1,
      marginLeft: 10,
      marginRight: 10,
      marginBottom: 10,
      marginTop: 30,
    },
    item: {
      padding: 10,
      fontSize: 18,
      height: 44,
      backgroundColor:'#fff8dc'
    },
    });
    