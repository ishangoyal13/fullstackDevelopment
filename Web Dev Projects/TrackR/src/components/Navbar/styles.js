import { makeStyles } from '@material-ui/core/styles'

export const useStyles = makeStyles((theme) => ({
  root: {
    flexGrow: 1,
  },

  title: {
    flexGrow: 1,
  },

  whiteLink: {
    color: '#fff',
    textDecoration: 'none',
  },
  blackLink: {
    color: theme.palette.alternate.main,
    textDecoration: 'none',
  },
}))
