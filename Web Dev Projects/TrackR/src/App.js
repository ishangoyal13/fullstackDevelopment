import {
  MuiThemeProvider,
  createTheme,
  responsiveFontSizes,
  CssBaseline,
  Paper,
} from '@material-ui/core'

import { BrowserRouter as Router, Switch, Route, Link } from 'react-router-dom'

// components
import Navbar from './components/Navbar/Navbar.jsx'

// screens
import Home from './screens/Home/Home'
import Add from './screens/Add/Add.jsx'
import Watchlist from './screens/Watchlist/Watchlist.jsx'
import Watched from './screens/Watched/Watched.jsx'

const App = () => {
  const theme = responsiveFontSizes(
    createTheme({
      typography: {
        fontFamily: '"Ubuntu"',
        color: {
          main: '#fff',
          secondary: 'rgba(255, 255, 255, 0.7)',
          disabled: 'rgba(255, 255, 255, 0.5)',
        },
      },
      palette: {
        type: 'dark',
        primary: { main: '#032541' },
        secondary: { main: '#66DE93' },
        alternate: { main: '#161616' },
        background: {
          default: '#043359',
        },
      },
    })
  )

  return (
    <div className='app'>
      <MuiThemeProvider theme={theme}>
        <CssBaseline />
        <Router>
          <Navbar />
          <Switch>
            <Route exact path='/' component={Home} />
            <Route path='/add' component={Add} />
            <Route path='/watchlist' component={Watchlist} />
            <Route path='/watched' component={Watched} />
          </Switch>
        </Router>
      </MuiThemeProvider>
    </div>
  )
}

export default App
