import React from 'react';
import { StyleSheet, View, Text, ImageBackground } from 'react-native';

const FullScreenBackgroundImage = () => {
  return (
    <ImageBackground
      source={{ uri: 'https://www.vietnamworks.com/hrinsider/wp-content/uploads/2023/12/hinh-nen-dien-thoai-19.jpg' }} 
      // Đường dẫn đến hình ảnh của bạn
      style={styles.backgroundImage}
    >
      <View style={styles.overlay}>
        <Text style={styles.text}>Welcome!</Text>
      </View>
    </ImageBackground>
  );
};

const styles = StyleSheet.create({
  backgroundImage: {
    flex: 1,
    resizeMode: 'cover', // Đảm bảo hình ảnh được bao phủ toàn bộ màn hình
    justifyContent: 'center',
    alignItems: 'center',
  },
  text: {
    color: '#fff',
    fontSize: 24,
    fontWeight: 'bold',
    textAlign: 'center',
  },
});

export default FullScreenBackgroundImage;
