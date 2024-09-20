import { StatusBar } from 'expo-status-bar';
import { StyleSheet, Text, View } from 'react-native';

export default function App() {
  return (
    <View style={styles.container}>
     <View style={styles.dong}>
       <View style={styles.cot1}></View>
       <View style={styles.cot2}></View>
       <View style={styles.cot1}></View>
       <View style={styles.cot2}></View>
     </View>
     <View style={styles.dong}>
       <View style={styles.cot1}></View>
       <View style={styles.cot2}></View>
       <View style={styles.cot1}></View>
       <View style={styles.cot2}></View>
     </View>
     <View style={styles.dong}>
       <View style={styles.cot1}><Text>a</Text></View>
       <View style={styles.cot2}></View>
       <View style={styles.cot1}></View>
       <View style={styles.cot2}></View>
     </View>
     <View style={styles.dong}>
       <View style={styles.cot1}></View>
       <View style={styles.cot2}></View>
       <View style={styles.cot1}></View>
       <View style={styles.cot2}></View>
     </View>
     <View style={styles.dong}>
       <View style={styles.cot1}></View>
       <View style={styles.cot2}></View>
       <View style={styles.cot1}></View>
       <View style={styles.cot2}></View>
     </View>
    </View>
  );
}

const styles = StyleSheet.create({
  container: {
    flex: 1,
    flexDirection:"column",
    backgroundColor: '#fff',
    alignItems: 'center',
    justifyContent: 'center',
  },
  dong:{
    flexDirection:"row",
    flex:1
  },
  cot1 :{
    flex:1,
    backgroundColor:"blue",
    borderStyle:"solid",
    borderWidth:1,
    borderColor:"fffaf0"
  },
  cot2:{
    flex:1,
    backgroundColor:"red",
    borderStyle:"solid",
    borderWidth:1,
    borderColor:"fffaf0"
  }
});
