import { View, Text,FlatList,StyleSheet} from 'react-native'
import React from 'react'

export default function PageLoaihoa({ navigation }) {
    const Listloaihoa = [
        {
         "maloai":"1",
          "tenloai": "Hoa Quà tặng",
          "hinh":require('../assets/images/cuc_1.jpg')
        },
        {
            "maloai":"2",
            "tenloai": 'Hoa Cưới',
            "hinh": require('../assets/images/cuoi_1.jpg')
        },
        {
            "maloai":"3",
            "tenloai": 'Hoa Hồng',
            "hinh": require('../assets/images/hong_1.jpg')
        },
        {
            "maloai":"4",
            "tenloai": 'Hoa Xuân',
            "hinh": require('../assets/images/xuan_1.jpg')
        }  
         ];
         const ItemView = ({item}) => {
            return (
              <View >
                <Text style={styles.textf}
                onPress={()=>{navigation.navigate('PageHoa',{tenloai:item.tenloai})}}
                 >{item.tenloai}</Text>
              </View>
            );
          };
          const ItemSeparatorView = () => {
            return ( 
              <View
                  style={{
                      height: 0.5,
                      width: '100%',
                      backgroundColor: '#C8C8C8'
                  }}
              />
            );
          };
  return (

         <View style={styles.container}>
      <FlatList
        data={Listloaihoa}
        //data defined in constructor
        ItemSeparatorComponent={ItemSeparatorView}
        //Item Separator View
        renderItem={ItemView}
        keyExtractor={(item, index) => index.toString()}
      />
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
      marginTop: 10,
      backgroundColor:"beige"
    },
    item: {
      padding: 10,
      fontSize: 18,
      height: 44,
      color:"aqua"
    },
    textf:{
        fontSize: 18,
        
        color:"blue"
    }
    });
    