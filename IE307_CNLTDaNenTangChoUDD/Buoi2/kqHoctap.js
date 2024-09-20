
import { Button, StyleSheet, Text, TextInput, View } from 'react-native';
import { useState } from 'react';
export default function App() {
  const [hk1,ganhk1]=useState(0);
  const [hk2,ganhk2]=useState(0);
  const [tb,gantb]=useState(0);
  const [kq,gankq]=useState(0);
  const TinhDiemTB=()=>{
    var diemtb=(hk1*2+hk2*1)/3;
var xl="";
    gantb (diemtb.toFixed(2).toString());
    if(diemtb>=8)
      xl="Giỏi";
    else if(diemtb>=6.5)
      xl="Khá";
    else if(diemtb>=5)
      xl="Trung Bình";
    else
    xl="Yếu";
  gankq(xl);
  }
  return (
    <View style={styles.container}>
     <View style={styles.dong}>
       <Text style={styles.tieude} >Kết Quả Học Tập</Text>
     </View>
    
     <View style={styles.dong}>
       <Text style={styles.cot1}>Học Kỳ 1</Text>
       <TextInput 
       style={styles.cot2}
       value={hk1}
       onChangeText={ganhk1}

       ></TextInput>
     </View>
     <View style={styles.dong}>
       <Text style={styles.cot1}>Học Kỳ 2</Text>
       <TextInput 
       style={styles.cot2}
       value={hk2}
       onChangeText={ganhk2}
       ></TextInput>
     </View>
     <View style={styles.dong}>
       <Text style={styles.cot1}>Điểm TB</Text>
       <TextInput style={styles.cot3 } readOnly="true"
        value={tb}
    
       ></TextInput>
     </View>
     <View style={styles.dong}>
       <Text style={styles.cot1}>Kết Quả</Text>
       <TextInput style={styles.cot3} readOnly="true"
        value={kq}
        
       ></TextInput>
     </View>
     <View style={styles.dong}>
       <Button title='Tính' onPress={()=>{
        TinhDiemTB();
       }}></Button>
     </View>
    </View>
  );
}

const styles = StyleSheet.create({
  container: {
    marginTop:20,
    flex: 1,
    flexDirection:"column",
    backgroundColor: '#fff',
    alignItems: 'center',
    justifyContent:'flex-start',
  },
  dong:{
    flexDirection:"row",
    height:40,
    width:"80",
    margin:10
  },
  cot1 :{
    flex:1,
    justifyContent:'center'
  },
  cot2:{
    flex:2,
    borderStyle:"solid",
    borderWidth:1,
    borderColor:"fffaf0",
    textAlign:"right"
  },
  cot3:{
    flex:2,
    borderStyle:"solid",
    borderWidth:1,
    borderColor:"fffaf0",
    textAlign:"right",
    backgroundColor:"mistyrose",
    color:"orangered"
  },
  tieude:{
    fontSize:30,
    backgroundColor:"red",
    color:"wheat",
    flex:1,
    textAlign:"center",
    textAlignVertical:"center"
  }
});
