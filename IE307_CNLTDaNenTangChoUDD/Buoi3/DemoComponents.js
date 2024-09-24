
import { StyleSheet, Text,TextInput,Button, View } from 'react-native';
import Cheader from './components/Cheader';
import Cfooter from './components/Cfooter';
import Cmenu from './components/Cmenu';
import CContent from './components/CContent';
import { useState } from 'react';
export default function App() {
  const [hoten,ganhoten]=useState('');
  return (
    <View style={styles.container}>
        
      <View style={styles.sheader}>
      <Cheader thongtin={hoten}  />
      </View>
      <View>
        <Text>Nhập Họ Tên</Text>
       <TextInput value={hoten} />
      </View>
    <View style={styles.scontent} >
     <View style={styles.styleleft}><Cmenu/></View>
    <View style={styles.styleright}><CContent/></View>
     </View>
     <View style={styles.sheader}>
     <Cfooter ganthongtin={ganhoten}/>
     </View>
    </View>
  );
}
const styles = StyleSheet.create({
  container: {
    flex: 1,
    marginTop:20,
    backgroundColor: '#fff',
    alignItems: 'flex-start',
    justifyContent: 'flex-start',
  },
  sheader:{
    flex:1,
    backgroundColor:"darkturquoise",
    width:"100%"
  },
  scontent :{
    flex:5,
    backgroundColor:"blue",
   flexDirection:"row",
   width:"100%"
  },
  styleleft:{
    flex:1,
    backgroundColor:"red",
  
  },
  styleright:{
    flex:3,
    backgroundColor:"cyan",
  
  }

});
