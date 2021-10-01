import { makeStyles } from '@material-ui/core/styles'

export const useStyles = makeStyles((theme) => ({
  wrapper: {
    padding: '18rem',
  },
  header: {
    marginTop: '-10rem',
    display: 'flex',
    alignItems: 'center',
    justifyContent: 'center',
  },
  inputWrapper: {
    display: 'flex',
    alignItems: 'center',
    justifyContent: 'center',
  },

  search: {
    marginTop: '8rem',
    width: '70rem',
  },

  cssOutlinedInput: {
    '&$cssFocused $notchedOutline': {
      borderColor: `${theme.palette.secondary.main} !important`,
    },
  },

  cssFocused: {},

  notchedOutline: {
    borderWidth: '1px',
  },

  results: {
    marginTop: '5rem',
  },
  loader: {
    width: '100%',
    '& > * + *': {
      marginTop: theme.spacing(2),
    },
  },
  alert: {
    width: '100%',
    marginTop: '2rem',
    '& > * + *': {
      marginTop: theme.spacing(2),
    },
  },
}))
