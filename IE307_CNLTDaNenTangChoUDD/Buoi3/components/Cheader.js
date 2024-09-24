import { View, Text } from 'react-native'
import React from 'react'

export default function Cheader({thongtin}) {
  return (
    <View>
      <Text>Thông Tin Header </Text>
      <Text>Chào {thongtin}</Text>
    </View>
  )
}