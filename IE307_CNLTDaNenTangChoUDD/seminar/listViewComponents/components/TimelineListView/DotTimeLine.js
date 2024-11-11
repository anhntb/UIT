// Show Timeline using React Native Timeline ListView
// https://aboutreact.com/react-native-timeline-listview/

// import React in our code
import React from 'react';

// import all the components we are going to use
import {StyleSheet, Text, View} from 'react-native';

// import Timeline
import Timeline from 'react-native-timeline-flatlist';

const DotTimeLine = () => {
  const data = [
    {
      time: '09:00',
      title: 'Event 1',
      description:
        'Lorem Ipsum is simply dummy text of the printing.',
      circleColor: '#009688',
      lineColor: '#009688',
    },
    {
      time: '10:45',
      title: 'Event 2',
      description:
        'Lorem Ipsum is simply dummy text of the printing.',
    },
    {
      time: '14:00',
      title: 'Event 4',
      description:
        'Lorem Ipsum is simply dummy text of the printing.',
      lineColor: '#009688',
    },
    {
      time: '16:30',
      title: 'Event 5',
      description:
        'Lorem Ipsum is simply dummy text of the printing.',
      circleColor: '#009688',
    },
  ];

  //'rgb(45,156,219)'
  return (
    <View style={styles.container}>
      <Text style={styles.title}>Dot TimeLine Example</Text>
      <Timeline
        data={data}
        circleSize={20}
        circleColor="rgb(45,156,219)"
        lineColor="rgb(45,156,219)"
        timeContainerStyle={{minWidth: 52, marginTop: -5}}
        timeStyle={{
          textAlign: 'center',
          backgroundColor: '#ff9797',
          color: 'white',
          padding: 5,
          borderRadius: 13,
        }}
        descriptionStyle={{color: 'gray'}}
        options={{
          style: {paddingTop: 5},
        }}
        innerCircle={'dot'}
      />
    </View>
  );
};

const styles = StyleSheet.create({
  container: {
    flex: 1,
  },
  title: {
    padding: 16,
    fontSize: 20,
    textAlign: 'center',
    fontWeight: 'bold',
  },
});

export default DotTimeLine;