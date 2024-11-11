import React from 'react';
import { SafeAreaView, StyleSheet } from 'react-native';
import FastImage from 'react-native-fast-image';

const FastSpeedImage = () => {
  return (
    <SafeAreaView style={styles.container}>
      <FastImage
        style={styles.image}
        source={{
          uri: 'https://inkythuatso.com/uploads/thumbnails/800/2022/05/1-hinh-nen-dien-thoai-nhe-nhanh-inkythuatso-19-16-29-37.jpg',
          headers: { Authorization: 'my-image' }, // Thêm tiêu đề ủy quyền nếu cần
          priority: FastImage.priority.high, // Đặt độ ưu tiên cao cho tải hình ảnh
        }}
        resizeMode={FastImage.resizeMode.cover} // Kiểu hiển thị hình ảnh
      />
    </SafeAreaView>
  );
};

const styles = StyleSheet.create({
  container: {
    flex: 1,
    justifyContent: 'center',
    alignItems: 'center',
  },
  image: {
    width: 300,
    height: 300,
    borderRadius: 15, // Bo tròn góc hình ảnh
  },
});

export default FastSpeedImage;
