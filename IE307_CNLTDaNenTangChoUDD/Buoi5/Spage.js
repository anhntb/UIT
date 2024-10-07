import { View, Text,Button } from 'react-native'
import React from 'react'
import DangKy from './DangKy'
import DangNhap from './DangNhap'
//Xử dụng tab
import { createBottomTabNavigator } from '@react-navigation/bottom-tabs';
//Sử dụng Icon
import
 MaterialCommunityIcons
from 'react-native-vector-icons/MaterialCommunityIcons';
const Tab = createBottomTabNavigator();
export default function Spage() {
   
  return (
    <Tab.Navigator
    initialRouteName="DangKy"
    screenOptions={({ route }) => ({
      headerStyle: { backgroundColor: '#42f44b' },
      headerTintColor: '#fff',
      headerTitleStyle: { fontWeight: 'bold' },
      tabBarActiveTintColor: 'tomato',
      tabBarInactiveTintColor: 'gray',
      tabBarIcon: ({ focused, color, size }) => {
        let iconName;
        if (route.name === 'DangKy') {
          iconName = focused
            ? 'account-circle'
            : 'account-circle-outline';
        } else if (route.name === 'DangNhap') {
          iconName = focused
            ? 'account-cowboy-hat'
            : 'account-cowboy-hat-outline';
        }
        return (
          <MaterialCommunityIcons
            name={iconName}
            size={size}
            color={color}
          />
        );
      }
    })}
    >
        <Tab.Screen
          name="DangKy"
          component={DangKy}
          options={{
            tabBarLabel: 'Đăng Ký',
            title: 'Đăng Ký',
          }}  />
        <Tab.Screen
          name="DangNhap"
          component={DangNhap}
          options={{
            tabBarLabel: 'Đăng Nhập',
            title: 'Đăng Nhập'
          }} />
      </Tab.Navigator>
  )
}