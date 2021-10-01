import { createStore, applyMiddleware } from 'redux'
import thunk from 'redux-thunk'
import { composeWithDevTools } from 'redux-devtools-extension'
import rootReducer from './reducers/IndexReducer'

const middleware = [thunk]

const watchlistFromStorage = localStorage.getItem('watchlist')
  ? JSON.parse(localStorage.getItem('watchlist'))
  : []
const watchedFromStorage = localStorage.getItem('watched')
  ? JSON.parse(localStorage.getItem('watched'))
  : []

const initialState = {
  watchlist: {
    watchlistMovies: watchlistFromStorage,
    watchedMovies: watchedFromStorage,
  },
}

const store = createStore(
  rootReducer,
  initialState,
  composeWithDevTools(applyMiddleware(...middleware))
)

export default store
