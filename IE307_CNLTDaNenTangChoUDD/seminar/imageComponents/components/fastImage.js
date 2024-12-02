// Fast Speed Image Loading using React Native Fast Image
// https://aboutreact.com/react-native-fast-image/

// import React in our code
import React, {useState, useEffect} from 'react';

// import all the components we are going to use
import {
  SafeAreaView,
  StyleSheet,
  Text,
  View,
  ScrollView,
  TouchableOpacity,
  Image,
  FlatList,
} from 'react-native';

// import Fast Image
import FastImage from 'react-native-fast-image';

const App = () => {
  const [showGrid, setShowGrid] = useState(false);
  const [dataSource, setDataSource] = useState([]);

  useEffect(() => {
    let items = Array.apply(null, Array(60)).map((v, i) => {
      return {
        id: i,
        src: 'https://unsplash.it/400/400?image=' + (i + 1)
      };
    });
    setDataSource(items);
  }, []);

  return (
    <SafeAreaView style={styles.container}>
      <View style={styles.container}>
        {!showGrid ? (
          <ScrollView style={{flex: 1}}>
            <View style={styles.container}>
              <Text style={styles.titleStyle}>
                Example of React native Fast Image
              </Text>

              <View
                style={{
                  padding: 16,
                  flexDirection: 'row',
                  marginTop: 20
                }}>
                <FastImage
                  style={styles.imageStyle}
                  source={{
                    uri: 'https://unsplash.it/400/400?image=1',
                    headers: {Authorization: '9876543210'},
                  }}
                />
                {/* FastImage cơ bản với source và header */}
                <Text style={{flex: 1, textAlign: 'center'}}>
                  Simple FastImage {'\n'} source + header 
                </Text>
              </View>

              <View
                style={{
                  padding: 16,
                  flexDirection: 'column',
                  marginTop: 20
                }}>
                {/* FastImage khác nhau với độ ưu tiên khác nhau: giúp kiểm soát thứ tự tải hình ảnh */}
                <Text style={{textAlign: 'center'}}>
                Different FastImage with different priority
                </Text>
                <View
                  style={{
                    flexDirection: 'row',
                    marginTop: 20,
                    justifyContent: 'center',
                    alignItems: 'center',
                  }}>
                  <FastImage
                    style={styles.imageStyle}
                    source={{
                      uri: 'https://unsplash.it/400/400?image=2',
                      headers: {Authorization: '9876543210'},
                      priority: FastImage.priority.low,
                    }}
                  />
                  <FastImage
                    style={styles.imageStyle}
                    source={{
                      uri: 'https://unsplash.it/400/400?image=3',
                      headers: {Authorization: '9876543210'},
                      priority: FastImage.priority.normal,
                    }}
                  />
                  <FastImage
                    style={styles.imageStyle}
                    source={{
                      uri: 'https://unsplash.it/400/400?image=4',
                      headers: {Authorization: '9876543210'},
                      priority: FastImage.priority.high,
                    }}
                  />
                </View>
              </View>

              <View
                style={{
                  padding: 16,
                  flexDirection: 'column',
                  marginTop: 20
                }}>
                {/* FastImage khác nhau với resizeMode khác nhau
                  Contain: Giữ tỷ lệ khung hình, không cắt bớt hình ảnh.
                  Cover: Giữ tỷ lệ khung hình, có thể cắt bớt hình ảnh.
                  Center: Giữ hình ảnh ở giữa, không thay đổi kích thước. */}
                <Text style={{textAlign: 'center'}}>
                  Different FastImage with different resizeMode
                </Text>
                <View
                  style={{
                    flexDirection: 'row',
                    marginTop: 20,
                    justifyContent: 'center',
                  }}>
                  <FastImage
                    style={styles.imageStyle}
                    source={{
                      uri: 'https://unsplash.it/400/400?image=5',
                      headers: {Authorization: '9876543210'},
                      priority: FastImage.priority.normal,
                    }}
                    resizeMode={FastImage.resizeMode.contain}
                  />
                  <FastImage
                    style={styles.imageStyle}
                    source={{
                      uri: 'https://unsplash.it/400/400?image=5',
                      headers: {Authorization: '9876543210'},
                      priority: FastImage.priority.normal,
                    }}
                    resizeMode={FastImage.resizeMode.cover}
                  />
                </View>
                <View
                  style={{
                    flexDirection: 'row',
                    marginTop: 10,
                    justifyContent: 'center',
                  }}>
                  <FastImage
                    style={styles.imageStyle}
                    source={{
                      uri: 'https://unsplash.it/400/400?image=5',
                      headers: {Authorization: '9876543210'},
                      priority: FastImage.priority.normal,
                    }}
                    resizeMode={FastImage.resizeMode.cover}
                  />
                  <FastImage
                    style={styles.imageStyle}
                    source={{
                      uri: 'https://unsplash.it/400/400?image=5',
                      headers: {Authorization: '9876543210'},
                      priority: FastImage.priority.normal,
                    }}
                    resizeMode={FastImage.resizeMode.center}
                  />
                </View>
              </View>
              <View
                style={{
                  padding: 16,
                  flexDirection: 'column',
                  marginTop: 20,
                  justifyContent: 'center',
                  alignItems: 'center',
                }}>
                  {/* FastImgae khác nhau với bộ nhớ đệm khác nhau
                  FastImage.cacheControl.immutable – (Mặc định) – Chỉ cập nhật nếu URL thay đổi.
                  FastImage.cacheControl.web – Sử dụng các tiêu đề và tuân theo các quy trình bộ nhớ đệm thông thường.
                  FastImage.cacheControl.cacheOnly – Chỉ hiển thị hình ảnh từ bộ nhớ đệm, không thực hiện bất kỳ yêu cầu mạng nào. */}
                <Text style={{textAlign: 'center'}}>
                  Different FastImage with different Cache
                </Text>
                <View
                  style={{
                    flexDirection: 'row',
                    marginTop: 20,
                    justifyContent: 'center',
                  }}>
                  <FastImage
                    style={styles.imageStyle}
                    source={{
                      uri: 'https://unsplash.it/400/400?image=6',
                      headers: {Authorization: '9876543210'},
                      priority: FastImage.priority.normal,
                      cache: FastImage.cacheControl.immutable,
                    }}
                  />
                  <FastImage
                    style={styles.imageStyle}
                    source={{
                      uri: 'https://unsplash.it/400/400?image=7',
                      headers: {Authorization: '9876543210'},
                      priority: FastImage.priority.normal,
                      cache: FastImage.cacheControl.web,
                    }}
                  />
                  <FastImage
                    style={styles.imageStyle}
                    source={{
                      uri: 'https://unsplash.it/400/400?image=8',
                      headers: {Authorization: '9876543210'},
                      priority: FastImage.priority.normal,
                      cache: FastImage.cacheControl.cacheOnly,
                    }}
                  />
                </View>
              </View>
              <View
                style={{
                  padding: 16,
                  flexDirection: 'column',
                  marginTop: 20,
                  justifyContent: 'center',
                  alignItems: 'center',
                }}>
                  {/* Fast Image với Gif*/}
                <Text style={{textAlign: 'center'}}>
                  Gif Support in React Native
                </Text>
                <View style={{flexDirection: 'row', marginTop: 20}}>
                  <FastImage
                    style={styles.imageStyle}
                    source={{
                      uri:
                        'https://cdn-images-1.medium.com/max/1600/1*-CY5bU4OqiJRox7G00sftw.gif',
                      headers: {Authorization: '9876543210'},
                      priority: FastImage.priority.normal,
                      cache: FastImage.cacheControl.immutable,
                    }}
                  />
                </View>
              </View>
              <View
                style={{
                  padding: 16,
                  flexDirection: 'column',
                  marginTop: 20,
                  justifyContent: 'center',
                  alignItems: 'center',
                }}>
                  {/* Điều chỉnh bán kính của góc ảnh: bo tròn góc */}
                <Text style={{textAlign: 'center'}}>
                  Controll the Corner Radius of Image
                </Text>
                <View style={{flexDirection: 'row', marginTop: 20}}>
                  <FastImage
                    style={{
                      borderRadius: 50,
                      height: 100,
                      backgroundColor: '#ddd',
                      margin: 20,
                      width: 100,
                      flex: 0,
                    }}
                    source={{
                      uri: 'https://unsplash.it/400/400?image=9',
                    }}
                  />
                  <FastImage
                    style={{
                      borderRadius: 50,
                      borderTopLeftRadius: 10,
                      borderBottomRightRadius: 10,
                      height: 100,
                      backgroundColor: '#ddd',
                      margin: 20,
                      flex: 1,
                    }}
                    source={{
                      uri: 'https://unsplash.it/400/400?image=9',
                    }}
                  />
                </View>
              </View>
              <View
                style={{
                  padding: 16,
                  flexDirection: 'column',
                  marginTop: 20,
                  justifyContent: 'center',
                  alignItems: 'center',
                }}>
                  {/* Fast Image với Callback: sử dụng các hàm callback để xử lý các sự kiện liên quan đến việc tải hình ảnh.
                   cho phép bạn thực hiện các hành động cụ thể khi hình ảnh được tải thành công hoặc khi có lỗi xảy ra trong quá trình tải hình ảnh. */}
                <Text style={{textAlign: 'center'}}>
                  Fast Image with Callback
                </Text>
                <View
                  style={{
                    flexDirection: 'row',
                    marginTop: 20,
                    justifyContent: 'center',
                  }}>
                  <FastImage
                    style={{height: 100, width: 100}}
                    source={{
                      uri: 'https://unsplash.it/400/400?image=9',
                    }}
                    onLoadStart={(e) => console.log('Loading Start')}
                    onProgress={(e) =>
                      console.log(
                        'Loading Progress ' +
                          e.nativeEvent.loaded / e.nativeEvent.total,
                      )
                    }
                    onLoad={(e) =>
                      console.log(
                        'Loading Loaded ' + e.nativeEvent.width,
                        e.nativeEvent.height,
                      )
                    }
                    onLoadEnd={(e) => console.log('Loading Ended')}
                  />
                </View>
              </View>
            </View>
          </ScrollView>
        ) : (
          <View style={{flex: 1}}>
            <FlatList
              data={dataSource}
              renderItem={({item}) => (
                <View
                  style={{
                    flex: 1,
                    flexDirection: 'column',
                    margin: 1
                  }}>
                  <FastImage
                    style={styles.imageThumbnailStyle}
                    source={{
                      uri: item.src,
                      priority: FastImage.priority.high,
                    }}
                  />
                </View>
              )}
              //Setting the number of column
              numColumns={3}
              keyExtractor={(item, index) => index}
            />
          </View>
        )}
        <TouchableOpacity
          activeOpacity={0.7}
          onPress={() => setShowGrid(!showGrid)}
          style={styles.touchableOpacityStyle}>
          <Image
            source={{
              uri:
                'https://raw.githubusercontent.com/AboutReact/sampleresource/master/plus_icon.png',
            }}
            style={styles.floatingButtonStyle}
          />
        </TouchableOpacity>
      </View>
    </SafeAreaView>
  );
};
export default App;
const styles = StyleSheet.create({
  container: {
    flex: 1,
    justifyContent: 'center',
    marginTop: 30,
  },
  titleStyle: {
    fontSize: 20,
    textAlign: 'center',
    margin: 10,
  },
  imageStyle: {
    height: 70,
    width: 100,
    marginRight: 10,
  },
  touchableOpacityStyle: {
    position: 'absolute',
    width: 50,
    height: 50,
    alignItems: 'center',
    justifyContent: 'center',
    right: 30,
    bottom: 30,
  },
  imageThumbnailStyle: {
    justifyContent: 'center',
    alignItems: 'center',
    height: 100,
  },
  floatingButtonStyle: {
    resizeMode: 'contain',
    width: 50,
    height: 50,
    //backgroundColor:'black'
  },
});