// React Native Full Screen Background Image
// https://aboutreact.com/react-native-full-screen-background-image/

// import React in our code
import React from 'react';

// import all the components we are going to use
import {
  SafeAreaView,
  View,
  Text,
  ImageBackground,
  StyleSheet,
  Image,
} from 'react-native';

const imageBackground = () => {
  return (
    <SafeAreaView style={styles.container}>
      <ImageBackground
        style={{flex: 1}}
        //We are using online image to set background
        source={{
          uri:
            'https://raw.githubusercontent.com/AboutReact/sampleresource/master/crystal_background.jpg',
        }}
        //You can also set image from your project folder
        //require('./images/background_image.jpg')
      >
        <View style={styles.container}>
          <Text style={styles.titleStyle}>
            React Native Full Screen Background Image
          </Text>
          <View style={styles.centerContentStyle}>
            <Image
              source={{
                uri:
                  'https://raw.githubusercontent.com/AboutReact/sampleresource/master/logosmalltransparen.png',
              }}
              style={{
                width: 40,
                height: 40,
                marginTop: 90
              }}
            />
            <Text style={styles.TextStyle}>
              AboutReact
            </Text>
          </View>
        </View>
      </ImageBackground>
    </SafeAreaView>
  );
};
export default imageBackground;
const styles = StyleSheet.create({
  container: {
    flex: 1,
    padding: 10,
  },
  titleStyle: {
    fontSize: 28,
    fontWeight: 'bold',
    textAlign: 'center',
    padding: 10,
  },
  centerContentStyle: {
    justifyContent: 'center',
    alignItems: 'center',
  },
});