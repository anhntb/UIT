// Example of Slider Image Gallery in React Native
// https://aboutreact.com/example-of-slider-image-gallery-in-react-native/

// import React in our code
import React, {useState, useEffect} from 'react';

// import all the components we are going to use
import {
  SafeAreaView,
  StyleSheet,
  View
} from 'react-native';

//import React in our project
import Gallery from 'react-native-image-gallery';

const SliderImageGallery = () => {
  const [items, setItems] = useState([]);

  useEffect(() => {
    let items = Array.apply(null, Array(60)).map((v, i) => {
      //Loop to make image array to show in slider
      return {
        source: {
          uri: 'http://placehold.it/200x200?text=' + (i + 1),
        },
      };
    });
    setItems(items);
  }, []);

  return (
    <SafeAreaView style={styles.container}>
      <View style={styles.container}>
        <Gallery
          style={{flex: 1, backgroundColor: 'black'}}
          initialPage="1"
          //initial image to show
          images={items}
        />
      </View>
    </SafeAreaView>
  );
};

export default SliderImageGallery;

const styles = StyleSheet.create({
  container: {
    flex: 1,
    justifyContent: 'center',
    marginTop: 30,
  },
});