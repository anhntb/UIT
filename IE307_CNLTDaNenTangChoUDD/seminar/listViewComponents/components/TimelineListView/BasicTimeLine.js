// Show Timeline using React Native Timeline ListView
// https://aboutreact.com/react-native-timeline-listview/

// import React in our code
import React from 'react';

// import all the components we are going to use
import {StyleSheet, Text, View} from 'react-native';

// import Timeline
import Timeline from 'react-native-timeline-flatlist';

const BasicTimeLine = () => {
  const data = [
    {
      time: '09:00',
      title: 'Event 1',
      description:
        'Lorem Ipsum is simply dummy text of the printing.',
    },
    {
      time: '10:45',
      title: 'Event 2',
      description:
        'Lorem Ipsum is simply dummy text of the printing.',
    },
    {
      time: '12:00',
      title: 'Event 3',
      description:
        'Lorem Ipsum is simply dummy text of the printing.',
    },
    {
      time: '14:00',
      title: 'Event 4',
      description:
        'Lorem Ipsum is simply dummy text of the printing.',
    },
    {
      time: '16:30',
      title: 'Event 5',
      description:
        'Lorem Ipsum is simply dummy text of the printing.',
    },
  ];

  return (
    <View style={styles.container}>
      <Text style={styles.title}>Basic TimeLine Example</Text>
      <Timeline data={data} />
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

export default BasicTimeLine;