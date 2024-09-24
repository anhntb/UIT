import { View, Text,TextInput } from 'react-native'
import React from 'react'

export default function Cfooter({ganthongtin}) {
  return (
    <View>
      <Text>Cfooter</Text>
      <View>
        <Text>Nhập Họ Tên Con</Text>
       <TextInput onChangeText={ganthongtin} />
       
      </View>
    </View>
  )
}