import { View, Text,Button,TextInput } from 'react-native'
import { useState } from 'react'
export default function Fpage({navigation}) {
    const [hoten,ganhoten]=useState('');
  return (
    <View>
      <Text>Màn Hình Chính</Text>
      <Text>Nhập vào họ tên</Text>
      <TextInput value={hoten} onChangeText={ganhoten}/>
      <Button title='Màn Hình 2' 
      onPress={()=>{navigation.navigate("SecondPage",{ht:hoten})}}/>
      <Button title='Màn Hình 3'
       onPress={()=>{navigation.navigate("ThirdPage")}}/>
 
    </View>
  )
}