// Show Timeline using React Native Timeline ListView
// https://aboutreact.com/react-native-timeline-listview/

// import React in our code
import React, {useState} from 'react';

// import all the components we are going to use
import {
  StyleSheet,
  Text,
  View,
  RefreshControl,
  ActivityIndicator,
} from 'react-native';

// import Timeline
import Timeline from 'react-native-timeline-flatlist';

const RefreshLoadMoreTimeLine = () => {
  let timeLineContent = [
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
      title: 'Lunch',
      icon: require('../img/place_holder.png')
    },
    {
      time: '14:00',
      title: 'Event 3',
      description:
        'Lorem Ipsum is simply dummy text of the printing.',
    },
    {
      time: '16:30',
      title: 'Event 4',
      description:
        'Lorem Ipsum is simply dummy text of the printing.',
    },
  ];

  // Setting up state
  const [isRefreshing, setIsRefreshing] = useState(false);
  const [waiting, setWaiting] = useState(false);
  const [data, setData] = useState(timeLineContent);

  const onRefresh = () => {
    setIsRefreshing(true);
    //refresh to initial data
    setTimeout(() => {
      //refresh to initial data
      setData(data);
      setIsRefreshing(false);
    }, 2000);
  };

  const onEndReached = () => {
    if (!waiting) {
      setWaiting(true);
      //fetch and concat data
      setTimeout(() => {
        //refresh to initial data
        let timeLineContent = data.concat([
          {
            time: '18:00',
            title: 'More Loaded Event 5',
            description:
              'Lorem Ipsum is simply dummy text of the printing.',
          },
          {
            time: '18:00',
            title: 'More Loaded Event 6',
            description:
              'Lorem Ipsum is simply dummy text of the printing.',
          },
          {
            time: '18:00',
            title: 'More Loaded Event 7',
            description:
              'Lorem Ipsum is simply dummy text of the printing.',
          },
          {
            time: '18:00',
            title: 'More Loaded Event 8',
            description:
              'Lorem Ipsum is simply dummy text of the printing.',
          },
          {
            time: '18:00',
            title: 'More Loaded Event 9',
            description:
              'Lorem Ipsum is simply dummy text of the printing.',
          },
        ]);
        setWaiting(false);
        setData(timeLineContent);
      }, 2000);
    }
  };

  const renderFooter = () => {
    if (waiting) {
      return <ActivityIndicator />;
    } else {
      return <Text>~</Text>;
    }
  };

  //'rgb(45,156,219)'
  return (
    <View style={styles.container}>
      <Text style={styles.title}>Refresh Load More Example</Text>
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
          refreshControl: (
            <RefreshControl
              refreshing={isRefreshing}
              onRefresh={onRefresh}
            />
          ),
          renderFooter: renderFooter,
          onEndReached: onEndReached,
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

export default RefreshLoadMoreTimeLine;