// Navigate Between Screens using React Navigation in React Native //
// https://aboutreact.com/react-native-stack-navigation //



import { NavigationContainer } from '@react-navigation/native';
import { createNativeStackNavigator } from '@react-navigation/native-stack';
import Fpage from './pages/Fpage';
import Spage from './pages/Spage';
import Tpage from './pages/Tpage';
const Stack = createNativeStackNavigator();
function App() {
  return (
    <NavigationContainer>
      <Stack.Navigator initialRouteName="FirstPage">
        <Stack.Screen  name="FirstPage"  component={Fpage}   />
        <Stack.Screen   name="SecondPage"   component={Spage}  />
        <Stack.Screen   name="ThirdPage"    component={Tpage}  />
      </Stack.Navigator>
    </NavigationContainer>
  );
}

export default App;