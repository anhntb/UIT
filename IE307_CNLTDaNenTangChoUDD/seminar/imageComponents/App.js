// Example of Slider Image Gallery in React Native
// https://aboutreact.com/example-of-slider-image-gallery-in-react-native/

// import React in our code
import React, {useState, useEffect} from 'react';

// import all the components we are going to use
import {
  SafeAreaView,
  StyleSheet,
  View,
  ImageBackground
} from 'react-native';

//import React in our project
import Gallery from 'react-native-image-gallery';
import imageBackground from './components/imageBackground';
const App = () => {

  return (
    <imageBackground></imageBackground>
  );
};

export default App;

