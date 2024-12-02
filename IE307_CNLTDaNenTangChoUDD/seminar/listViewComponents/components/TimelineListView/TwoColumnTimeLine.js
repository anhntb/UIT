// Show Timeline using React Native Timeline ListView
// https://aboutreact.com/react-native-timeline-listview/

// import React in our code
import React from 'react';

// import all the components we are going to use
import {StyleSheet, Text, View} from 'react-native';

// import Timeline
import Timeline from 'react-native-timeline-flatlist';

const TwoColumnTmeLine = () => {
  const data = [
    {
      time: '09:00',
      title: 'Event 1',
      description:
        'Lorem Ipsum is simply dummy text of the printing.',
      lineColor: '#009688',
      icon: require('../img/place_holder.png'),
      imageUrl:
        'https://images.pexels.com/photos/2250394/pexels-photo-2250394.jpeg?auto=compress&cs=tinysrgb&dpr=2&h=250&w=250',
    },
    {
      time: '10:45',
      title: 'Event 2',
      description:
        'Lorem Ipsum is simply dummy text of the printing.',
      icon: require('../img/place_holder.png'),
      imageUrl:
        'https://images.pexels.com/photos/2250394/pexels-photo-2250394.jpeg?auto=compress&cs=tinysrgb&dpr=2&h=250&w=250',
    },
    {
      time: '12:00',
      title: 'Event 3',
      icon: require('../img/place_holder.png'),
    },
    {
      time: '14:00',
      title: 'Event 4',
      description:
        'Lorem Ipsum is simply dummy text of the printing.',
      lineColor: '#009688',
      icon: require('../img/place_holder.png'),
      imageUrl:
        'https://images.pexels.com/photos/2250394/pexels-photo-2250394.jpeg?auto=compress&cs=tinysrgb&dpr=2&h=250&w=250',
    },
    {
      time: '16:30',
      title: 'Event 5',
      description:
        'Lorem Ipsum is simply dummy text of the printing.',
      icon: require('../img/place_holder.png'),
      imageUrl:
        'https://images.pexels.com/photos/2250394/pexels-photo-2250394.jpeg?auto=compress&cs=tinysrgb&dpr=2&h=250&w=250',
    },
  ];

  return (
    <View style={styles.container}>
      <Text style={styles.title}>Two Column TimeLine Example</Text>
      <Timeline
        data={data}
        circleSize={20}
        circleColor="rgba(0,0,0,0)"
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
        innerCircle={'icon'}
        onEventPress={(item) => 
          alert(`${item.title} at ${item.time}`)
        }
        separator={false}
        detailContainerStyle={{
          marginBottom: 20,
          paddingLeft: 5,
          paddingRight: 5,
          backgroundColor: '#BBDAFF',
          borderRadius: 10,
        }}
        columnFormat="two-column"
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

export default TwoColumnTmeLine;