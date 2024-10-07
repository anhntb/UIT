import { View, Text,TextInput,Button,StyleSheet } from 'react-native'
import { useState } from 'react';
//Dùng Expo sqlite
import * as SQLite from 'expo-sqlite/legacy';
//Mở DataBase
const db = SQLite.openDatabase("qlbanhoap11.db")

export default function DangNhap() {
    const [tendn,gantendn]=useState('');
    const[matkhau,ganmatkhau]=useState('');
    const[email,ganemail]=useState('');
    const [nguoidung,gannguoidung]=useState({tendn:"",matkhau:"",email:""});
    //Tạo Bảng Người Dùng
    const KiemTraNguoiDung=()=>{
        db.transaction(function (txn) {  
          txn.executeSql(
            "SELECT * FROM tbluser where username=? and password=?",
            [tendn,matkhau],
            function (tx, res) {
                var temp = [];
              if (res.rows.length >0) {
                for (let i = 0; i < results.rows.length; ++i)
                    temp.push(results.rows.item(i));
                gannguoidung(temp[0]);
                  //  alert('Đăng nhập thành công chào bạn :'+nguoidung.tendn +',' +nguoidung.email);
              }
              else
              alert('Thông tin đăng nhập sai');
            })})}
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
       <Button title='Đăng Nhập' onPress={()=>{KiemTraNguoiDung()}}/>
        <Text>Chào Bạn :{nguoidung.tendn}</Text>
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
    