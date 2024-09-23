
import React, {useState} from 'react';
import {
  Modal,
  Button,
  View,
  Text,
  SafeAreaView,
  StyleSheet,
  Image
} from 'react-native';

const App = () => {
  const [showModal, setShowModal] = useState(false);
  return (
    <SafeAreaView style={{flex: 1}}>
      <View style={styles.container}>
        <Modal
          animationType={'slide'}
          transparent={false}
          visible={showModal}
          >
          <View style={styles.modal}>
            <Text style={styles.text}> Tên Hoa :Đón xuân</Text>
            <Text style={styles.text}> Đơn giá: 15000</Text>    
            <Image source={require('./assets/images/cuc_9.jpg')} /> 
          <Text>
        Mô Tả :Hoa hồng màu hồng đậm, hoa hồng xanh, các loại lá măng
        </Text>
            <Button
              title="Close"
              onPress={() => {
                setShowModal(!showModal);
              }}
            />
          </View>
        </Modal>
       
        <Button
          title="Hoa Hồng .."
          onPress={() => {
            setShowModal(!showModal);
          }}
        />
      </View>
    </SafeAreaView>
  );
};

const styles = StyleSheet.create({
  container: {
    flex: 1,
    alignItems: 'center',
    justifyContent: 'center',
    backgroundColor: '#ecf0f1',
    marginTop: 30,
  },
  modal: {
    flex: 1,
    alignItems: 'center',
    backgroundColor: '#00ff00',
    padding: 100,
  },
  text: {
    color: '#3f2949',
    marginTop: 10,
  },
});

export default App;