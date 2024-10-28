import { StyleSheet, Text, View ,Button} from 'react-native';
import axios from 'axios';
export default function App() {
  const Getallcategories = async () => {
    try {
      const response = await axios.get(
        'https://fakestoreapi.com/products/categories',
      );
      alert(JSON.stringify(response.data));
    } catch (error) {
      // handle error
      alert(error.message);
    }
  };
  const Getproductsincategory = async () => {
    try {
      const response = await axios.get(
        'https://fakestoreapi.com/products/category/jewelery',
      );
      alert(JSON.stringify(response.data));
    } catch (error) {
      // handle error
      alert(error.message);
    }
  };
  

  return (
    <View style={styles.container}>
      <Button title='Call WebAPI' onPress={()=>{Getallcategories()}}/>
      <Button title='Call WebAPIProduct' onPress={()=>{Getproductsincategory()}}/>
    </View>
  );
}

const styles = StyleSheet.create({
  container: {
    flex: 1,
    backgroundColor: '#fff',
    alignItems: 'center',
    justifyContent: 'center',
  },
});
