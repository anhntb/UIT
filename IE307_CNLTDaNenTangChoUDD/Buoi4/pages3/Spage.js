import { View, Text,Button } from 'react-native'
import React from 'react'

export default function Spage({navigation,route}) {
    var hoten=route.params.ht;
  return (
    <View>
      <Text>Màn Hình 2</Text>
      <Text>Chào Bạn :{hoten}</Text>
      <Button title='Màn Hình Chính' 
      onPress={()=>{navigation.goBack()}}/>
      <Button title='Màn Hình 3' 
      onPress={()=>{navigation.navigate("ThirdPage")}}/>

    </View>
  )
}