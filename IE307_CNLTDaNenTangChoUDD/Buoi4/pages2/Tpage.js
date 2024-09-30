import { View, Text,Button } from 'react-native'
import React from 'react'

export default function Tpage({navigation}) {
  return (
    <View>
      <Text>Màn Hình 3</Text>
      <Button title='Màn Hình Chính' onPress={()=>{navigation.popToTop()}}/>
      <Button title='Màn Hình Trước' onPress={()=>{navigation.goBack()}}/>

    </View>
  )
}