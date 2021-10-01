import { combineReducers } from 'redux'

import { searchReducer } from './SearchReducer'
import { watchlistReducer } from './WatchlistReducer'

const rootReducer = combineReducers({
  search: searchReducer,
  watchlist: watchlistReducer,
})

export default rootReducer
