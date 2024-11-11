// Show Timeline using React Native Timeline ListView
// https://aboutreact.com/react-native-timeline-listview/

// import React in our code
import React, {useState} from 'react';

// import all the components we are going to use
import {
  SafeAreaView,
  Text,
  View,
  StyleSheet,
  TouchableOpacity,
  ScrollView,
} from 'react-native';

import BasicTimeLine from './TimelineListView/BasicTimeLine';
import CustomTimeLine from './TimelineListView/CustomTimeLine';
import DotTimeLine from './TimelineListView/DotTimeLine';

const ShowTimelineListView = () => {
  const [val, setVal] = useState(1);

  const renderElement = () => {
    //You can add N number of Views here in if-else condition
    if (val === 1) {
      return <BasicTimeLine />;
    } else if (val === 2) {
      return <CustomTimeLine />;
    } else if (val === 3) {
      return <DotTimeLine />;
    }
  };

  const tabName = [
    'Basic TimeLine',
    'Custom TimeLine',
    'Dot TimeLine',
  ];

  return (
    <SafeAreaView style={styles.container}>
      <View style={styles.container}>
        <View>
          <ScrollView horizontal>
            <View style={{flexDirection: 'row'}}>
              {tabName.map((item, index) => {
                return (
                  <TouchableOpacity
                    key={index + 1}
                    style={[
                      styles.buttonStyle,
                      {
                        backgroundColor:
                          val == index + 1 ? 'orange' : '#808080',
                      },
                    ]}
                    onPress={() => setVal(index + 1)}>
                    <Text style={{color: '#ffffff'}}>
                      {item}
                    </Text>
                  </TouchableOpacity>
                );
              })}
            </View>
          </ScrollView>
        </View>
        {/*View to hold the child screens 
        which can be changed on the click of a button*/}
        <View style={styles.childContainer}>
          {renderElement()}
        </View>
      </View>
    </SafeAreaView>
  );
};
export default ShowTimelineListView;

const styles = StyleSheet.create({
  container: {
    flex: 1,
    backgroundColor: '#ffffff',
  },
  buttonStyle: {
    flex: 1,
    alignItems: 'center',
    padding: 10,
    margin: 2,
  },
  childContainer: {
    backgroundColor: '#f9f9f9',
    flex: 1,
    padding: 10,
  },
});